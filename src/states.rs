pub(crate) mod single_note_trainer;

pub(crate) enum StateTransition {
    DontTransition,
    GoTo(Box<dyn AppState>),
}
pub(crate) trait AppState {
    fn update(&mut self) -> StateTransition;
    fn draw(&self);
}
