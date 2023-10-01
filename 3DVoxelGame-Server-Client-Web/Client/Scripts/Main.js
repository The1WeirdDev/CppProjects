const canvas = document.getElementById("GameCanvas");
const gl = canvas.getContext("webgl2", { premultipliedAlpha: true, antialias: false });

function Main() {
    Init();
    setInterval(Update, 1000 / 60);
}

function Init() {
    Display.Init();
    window.addEventListener("resize", function () {
        canvas.width = this.innerWidth;
        canvas.height = this.innerHeight;
        gl.viewport(0, 0, this.innerWidth, this.innerHeight);
    });
    canvas.oncontextmenu = function (e) {
        e.preventDefault();
    };
}

function Update() {
    Display.Update();
    Draw();
}
function Draw() {

}

Main();