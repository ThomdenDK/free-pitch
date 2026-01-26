#![warn(clippy::todo)]
mod states;
use crate::states::{AppState, StateTransition, single_note_trainer::SingleNoteTrainer};
use macroquad::prelude::*;

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
