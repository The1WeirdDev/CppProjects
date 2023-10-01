const canvas = document.getElementById("GameCanvas");
const gl = canvas.getContext("webgl2", { premultipliedAlpha: true, antialias: false });

function Main() {
    Init();
    setInterval(Update, 1000 / 60);

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
}
function Draw() {
    Game.Draw();
}

Main();