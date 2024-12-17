import 
FreePitch::FreePitch(IWindow& win) : window(win) {}

void FreePitch::Run() {
    window.Open();

    while (1) {
        if (state->HandleAllEvents() < 0) break;
        this->DrawUI();
        this->Render();
    }
    
    window.Close();
}

void FreePitch::ChangeState(State* state) {
    this->state = state;
}

IWindow& FreePitch::GetWindow() {
    return window;
}