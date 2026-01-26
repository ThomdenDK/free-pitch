use std::{fs::File, sync::Arc};

use crate::states::{AppState, StateTransition};
use macroquad::prelude::*;
use rustysynth::{SoundFont, Synthesizer, SynthesizerSettings};

#[derive(Default)]
pub struct KeyConfig {
    key_ypos: f32,
    white_ids: Vec<usize>,
    black_ids: Vec<usize>,
    active_key: Option<usize>,
    black_key_width: f32,
    black_key_height: f32,
    white_key_width: f32,
    screen_height: f32,
    screen_width: f32,
    white_key_height: f32,
}

pub struct SingleNoteTrainer {
    key_config: KeyConfig,
    synth: Synthesizer,
}

impl SingleNoteTrainer {
    pub fn new() -> SingleNoteTrainer {
        let mut sfz = File::open("resources/piano.sfz").unwrap();
        let sound_font = Arc::new(SoundFont::new(&mut sfz).unwrap());
        // Create the synthesizer.
        let settings = SynthesizerSettings::new(44100);
        let synthesizer = Synthesizer::new(&sound_font, &settings).unwrap();

        SingleNoteTrainer {
            key_config: KeyConfig::default(),
            synth: synthesizer,
        }
    }
    fn get_white_left_edge(&self, id: usize) -> f32 {
        id as f32 * self.key_config.white_key_width / 2_f32
    }
    fn get_black_left_edge(&self, id: usize) -> f32 {
        (id + 1) as f32 * (self.white_key_width / 2_f32) - self.black_key_width / 2_f32
    }
}

/// Configure how many octaves to show (7 white keys per octave)
const NUM_OCTAVES: usize = 2;
const WHITE_PER_OCTAVE: usize = 7;
const NUM_WHITE_KEYS: usize = NUM_OCTAVES * WHITE_PER_OCTAVE;

impl AppState for SingleNoteTrainer {
    fn update(&mut self) -> StateTransition {
        self.screen_width = screen_width();
        self.screen_height = screen_height();
        self.white_key_width = self.screen_width / (NUM_WHITE_KEYS as f32);
        self.white_key_height = self.screen_height * 0.35;
        self.key_ypos = self.screen_height - self.white_key_height;
        self.black_key_width = self.white_key_width * 0.6;
        self.black_key_height = self.white_key_height * 0.62;
        self.white_ids = (0..NUM_WHITE_KEYS).map(|x| 2 * x).collect();
        self.black_ids = (0..NUM_WHITE_KEYS)
            .filter(|x| {
                let y = x % 7;
                y != 2 && y != 6
            })
            .map(|x| 2 * x + 1)
            .collect();

        // Handle mouse press: check blacks first (on top), then whites
        self.active_key = if is_mouse_button_down(MouseButton::Left) {
            let (mx, my) = mouse_position();
            let mut result: Option<usize> = None;
            for id in &self.black_ids {
                let left_edge = self.get_black_left_edge(*id);
                let right_edge = left_edge + self.black_key_width;
                let top_edge = self.key_ypos;
                let bottom_edge = self.key_ypos + self.black_key_height;
                if mx >= left_edge && mx <= right_edge && my <= bottom_edge && my >= top_edge {
                    result = Some(*id);
                    break;
                }
            }
            if result.is_none() {
                for id in &self.white_ids {
                    let left_edge = self.get_white_left_edge(*id);
                    let right_edge = left_edge + self.white_key_width;
                    let top_edge = self.key_ypos;
                    let bottom_edge = self.screen_height;
                    if mx >= left_edge && mx <= right_edge && my <= bottom_edge && my >= top_edge {
                        result = Some(*id);
                        break;
                    }
                }
            }
            result
        } else {
            None
        };
        StateTransition::DontTransition
    }

    fn draw(&self) {
        clear_background(Color::from_rgba(0, 0, 50, 255));

        // Draw whites (background first)
        for id in self.white_ids.iter() {
            let fill = if self.active_key == Some(*id) {
                Color::new(0.4, 0.7, 1.0, 1.0) // highlighted blue-ish
            } else {
                WHITE
            };
            let x = *id as f32 * (self.white_key_width / 2_f32);
            draw_rectangle(
                x,
                self.key_ypos,
                self.white_key_width,
                self.white_key_height,
                fill,
            );
            draw_rectangle_lines(
                x,
                self.key_ypos,
                self.white_key_width,
                self.white_key_height,
                2.0,
                BLACK,
            );
        }
        // Draw blacks on top
        for id in self.black_ids.iter() {
            let fill = if self.active_key == Some(*id) {
                Color::new(0.4, 0.7, 1.0, 1.0) // highlighted blue-ish
            } else {
                BLACK
            };
            let x =
                (*id + 1) as f32 * (self.white_key_width / 2_f32) - self.black_key_width / 2_f32;
            draw_rectangle(
                x,
                self.key_ypos,
                self.black_key_width,
                self.black_key_height,
                fill,
            );
        }

        // Draw simple labels on the white keys (C D E F G A B repeats)
        let note_names = ["C", "D", "E", "F", "G", "A", "B"];
        for i in 0..NUM_WHITE_KEYS {
            let x = self.white_ids[i] as f32 * (self.white_key_width / 2_f32) + 6.0;
            let y = self.key_ypos + self.white_key_height - 22.0;
            let name = note_names[i % 7];
            draw_text(name, x, y, 18.0, BLACK);
        }

        // UI hint
        let hint = "Click keys to highlight. Add sound via `rodio` or macroquad audio.";
        draw_text(hint, 10.0, 30.0, 18.0, Color::new(1.0, 1.0, 1.0, 1.0));

        let note = self.active_key.map(|id: usize| {
            note_names[id % 14 / 2].to_owned() + if id % 2 == 1 { "#" } else { "" }
        });
        let note_msg = if let Some(note_name) = note {
            format!("The current note is {note_name}")
        } else {
            String::from("No note is pressed")
        };
        draw_text(&note_msg, 10.0, 100.0, 40.0, Color::new(1.0, 1.0, 1.0, 1.0));
    }
}
