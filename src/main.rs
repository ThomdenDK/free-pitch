use macroquad::prelude::*;

enum StateTransition {
    DontTransition,
    GoTo(Box<dyn AppState>),
}
trait AppState {
    fn update(&mut self) -> StateTransition;
    fn draw(&self);
}
struct SingleNoteTrainer {
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

impl SingleNoteTrainer {
    fn new() -> SingleNoteTrainer {
        todo!()
    }
    fn get_white_left_edge(&self, id: usize) -> f32 {
        todo!()
    }
    fn get_black_left_edge(&self, id: usize) -> f32 {
        todo!()
    }
}

impl AppState for SingleNoteTrainer {
    fn update(&mut self) -> StateTransition {
        (self.screen_width, self.screen_height) = (screen_width(), screen_height());
        self.white_key_width = self.screen_width / (NUM_WHITE_KEYS as f32);
        self.white_key_height = self.screen_height * 0.35;
        self.key_ypos = self.screen_height - self.white_key_height;
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

        // Layout sizes

        let black_key_width = self.white_key_width * 0.6;
        let black_key_height = self.white_key_height * 0.62;

        let get_white_left_edge = |id: usize| id as f32 * self.white_key_width / 2_f32;
        let get_black_left_edge =
            |id: usize| (id + 1) as f32 * (self.white_key_width / 2_f32) - black_key_width / 2_f32;

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
            let x = (*id + 1) as f32 * (self.white_key_width / 2_f32) - black_key_width / 2_f32;
            draw_rectangle(x, self.key_ypos, black_key_width, black_key_height, fill);
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

        let note = self
            .active_key
            .map(|id| note_names[id % 14 / 2].to_owned() + if id % 2 == 1 { "#" } else { "" });
        let note_msg = if let Some(note_name) = note {
            format!("The current note is {note_name}")
        } else {
            String::from("No note is pressed")
        };
        draw_text(&note_msg, 10.0, 100.0, 40.0, Color::new(1.0, 1.0, 1.0, 1.0));
    }
}

/// Configure how many octaves to show (7 white keys per octave)
const NUM_OCTAVES: usize = 2;
const WHITE_PER_OCTAVE: usize = 7;
const NUM_WHITE_KEYS: usize = NUM_OCTAVES * WHITE_PER_OCTAVE;

#[macroquad::main("Macroquad Piano")]
async fn main() {
    // Initial state
    let mut state: Box<dyn AppState> = Box::new(SingleNoteTrainer::new());

    loop {
        let transition = state.update();
        if let StateTransition::GoTo(new_state) = transition {
            state = new_state
        }
        state.draw();
        next_frame().await;
    }
}
