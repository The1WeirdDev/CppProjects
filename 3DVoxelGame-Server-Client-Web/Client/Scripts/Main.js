const canvas = document.getElementById("GameCanvas");
const gl = canvas.getContext("webgl2", { premultipliedAlpha: true, antialias: false });

var movement_x = 0, movement_y = 0;
var cursor_locked = false;
var simplex = new SimplexNoise(Math);
function Main() {
    Init();
    //setInterval(Update, 1000 / 15);
    Update();
    /*
    Pretty sure javascript just discards all of its resources
    */
}

function Init() {
    Game.Init();
}

function Update() {
    Game.Update();
    Draw();

    requestAnimationFrame(Update);
}
function Draw() {
    Game.Draw();
}

Main();