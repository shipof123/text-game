#define houseButton (mouseX >= 400 && mouseX <= 410 && mouseY >= 40 && mouseY <= 55)
#define cityButton (mouseX >= 45 && mouseX <= 55 && mouseY >= 135  && mouseY <= 145)
#define alleyButton (mouseX >= 310 && mouseX <= 340&& mouseY >= 405  && mouseY <= 425)
//#define exButton (mouseX >= 220 && mouseY >= 305 && mouseX <= 235 && mouseY <=325) 
#define exButton (true)

typedef struct {
    SDL_Rect draw_rect;    // dimensions of button
    struct {
        Uint8 r, g, b, a;
    } colour;

    bool pressed;
} button_t;

static void button_process_event(button_t *btn, const SDL_Event *ev) {
    // react on mouse click within button rectangle by setting 'pressed'
    if(ev->type == SDL_MOUSEBUTTONDOWN) {
        if(ev->button.button == SDL_BUTTON_LEFT &&
                ev->button.x >= btn->draw_rect.x &&
                ev->button.x <= (btn->draw_rect.x + btn->draw_rect.w) &&
                ev->button.y >= btn->draw_rect.y &&
                ev->button.y <= (btn->draw_rect.y + btn->draw_rect.h)) {
            btn->pressed = true;
        }
    }
}

static bool button(SDL_Renderer *r, button_t *btn) {
    // draw button
    SDL_SetRenderDrawColor(r, btn->colour.r, btn->colour.g, btn->colour.b, btn->colour.a);
    SDL_RenderFillRect(r, &btn->draw_rect);

    // if button press detected - reset it so it wouldn't trigger twice
    if(btn->pressed) {
        btn->pressed = false;
        return true;
    }
    return false;
}