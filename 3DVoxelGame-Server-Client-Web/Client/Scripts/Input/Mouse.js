class Mouse {
    static mouse_x;
    static mouse_y;
    static last_mouse_x;
    static last_mouse_y;
    static mouse_delta_x;
    static mouse_delta_y;

    static Init() {

    }

    static Update() {
        Mouse.mouse_delta_x = Mouse.mouse_x - Mouse.last_mouse_x;
        Mouse.mouse_delta_y = Mouse.mouse_y - Mouse.last_mouse_y;
        Mouse.last_mouse_x = Mouse.mouse_x;
        Mouse.last_mouse_y = Mouse.mouse_y;

        if (!document.hasFocus()) {
            Mouse.mouse_delta_x = 0;
            Mouse.mouse_delta_y = 0;
        }
    }

    static OnMouseDown(e) { }
    static OnMouseUp(e) { }
    static OnMouseMove(e) {
        const rect = canvas.getBoundingClientRect();
        const x = e.clientX - rect.left;
        const y = e.clientY - rect.top;

        var linear_x = (x / canvas.clientWidth);
        var linear_y = (y / canvas.clientHeight);
        var normalized_x = linear_x * 2 - 1;
        var normalized_y = (linear_y * 2 - 1) * -1;

        Mouse.mouse_x = x;
        Mouse.mouse_y = y;
        Mouse.normalized_x = normalized_x;
        Mouse.normalized_y = normalized_y;
    }
}