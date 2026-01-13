use macroquad::prelude::*;

trait AppState {
    fn update(&self) -> Box<dyn AppState>;
    fn draw(&self);
}

struct MainMenu;
impl AppState for MainMenu {
    fn update(&self) -> Box<dyn AppState> {
        todo!()
    }

    fn draw(&self) {
        todo!()
    }
}

/// Configure how many octaves to show (7 white keys per octave)
const NUM_OCTAVES: usize = 2;
const WHITE_PER_OCTAVE: usize = 7;

#[macroquad::main("Macroquad Piano")]
async fn main() {
    // Initial state
    let mut state = Box::new(MainMenu);

    loop {
        state.update();
        state.draw();
    }
}
async fn piano() {
    let mut active_key: Option<usize> = None;

    loop {
        clear_background(Color::from_rgba(0, 0, 50, 255));

        let (screen_width, screen_height) = (screen_width(), screen_height());

        // Layout sizes
        let num_white_keys = NUM_OCTAVES * WHITE_PER_OCTAVE;

        let white_key_width = screen_width / (num_white_keys as f32);
        let white_key_height = screen_height * 0.35;
        let key_ypos = screen_height - white_key_height;

        let black_key_width = white_key_width * 0.6;
        let black_key_height = white_key_height * 0.62;

        let get_white_left_edge = |id: usize| id as f32 * white_key_width / 2_f32;
        let get_black_left_edge =
            |id: usize| (id + 1) as f32 * (white_key_width / 2_f32) - black_key_width / 2_f32;

        let white_ids: Vec<usize> = (0..num_white_keys).map(|x| 2 * x).collect();
        let black_ids: Vec<usize> = (0..num_white_keys)
            .filter(|x| {
                let y = x % 7;
                y != 2 && y != 6
            })
            .map(|x| 2 * x + 1)
            .collect();

        // Draw whites (background first)
        for id in white_ids.iter() {
            let fill = if active_key == Some(*id) {
                Color::new(0.4, 0.7, 1.0, 1.0) // highlighted blue-ish
            } else {
                WHITE
            };
            let x = *id as f32 * (white_key_width / 2_f32);
            draw_rectangle(x, key_ypos, white_key_width, white_key_height, fill);
            draw_rectangle_lines(x, key_ypos, white_key_width, white_key_height, 2.0, BLACK);
        }
        // Draw blacks on top
        for id in black_ids.iter() {
            let fill = if active_key == Some(*id) {
                Color::new(0.4, 0.7, 1.0, 1.0) // highlighted blue-ish
            } else {
                BLACK
            };
            let x = (*id + 1) as f32 * (white_key_width / 2_f32) - black_key_width / 2_f32;
            draw_rectangle(x, key_ypos, black_key_width, black_key_height, fill);
        }

        // Handle mouse press: check blacks first (on top), then whites
        active_key = if is_mouse_button_down(MouseButton::Left) {
            let (mx, my) = mouse_position();
            let mut result: Option<usize> = None;
            for id in black_ids {
                let left_edge = get_black_left_edge(id);
                let right_edge = left_edge + black_key_width;
                let top_edge = key_ypos;
                let bottom_edge = key_ypos + black_key_height;
                if mx >= left_edge && mx <= right_edge && my <= bottom_edge && my >= top_edge {
                    result = Some(id);
                    break;
                }
            }
            if result.is_none() {
                for id in &white_ids {
                    let left_edge = get_white_left_edge(*id);
                    let right_edge = left_edge + white_key_width;
                    let top_edge = key_ypos;
                    let bottom_edge = screen_height;
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

        // Draw simple labels on the white keys (C D E F G A B repeats)
        let note_names = ["C", "D", "E", "F", "G", "A", "B"];
        for i in 0..num_white_keys {
            let x = white_ids[i] as f32 * (white_key_width / 2_f32) + 6.0;
            let y = key_ypos + white_key_height - 22.0;
            let name = note_names[i % 7];
            draw_text(name, x, y, 18.0, BLACK);
        }

        // UI hint
        let hint = "Click keys to highlight. Add sound via `rodio` or macroquad audio.";
        draw_text(hint, 10.0, 30.0, 18.0, Color::new(1.0, 1.0, 1.0, 1.0));

        let note = active_key
            .map(|id| note_names[id % 14 / 2].to_owned() + if id % 2 == 1 { "#" } else { "" });
        let note_msg = if let Some(note_name) = note {
            format!("The current note is {note_name}")
        } else {
            String::from("No note is pressed")
        };
        draw_text(&note_msg, 10.0, 100.0, 40.0, Color::new(1.0, 1.0, 1.0, 1.0));
        next_frame().await;
    }
}
