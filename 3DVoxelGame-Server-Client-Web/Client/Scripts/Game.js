class Game {
    static player = null;
    static shader = null;
    static chunk_shader = null;
    static world = null;

    static Init() {
        Display.Init();
        Keyboard.Init();
        Mouse.Init();

        Game.shader = new Shader();
        Game.shader.Create(`precision mediump float;\nattribute vec2 position; void main(){gl_Position = vec4(position, 0.0, 1.0);}`,
            `precision mediump float;\nvoid main(){gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);}`);

        Game.chunk_shader = new ChunkShader();

        Game.world = new World();
        Game.world.Init();

        Game.player = new Player();
        Game.player.Init();

        Game.AddEventListeners();

        canvas.width = innerWidth;
        canvas.height = innerHeight;
        gl.viewport(0, 0, innerWidth, innerHeight);
    }

    static Update() {
        Display.Update();
        Keyboard.Update();
        Mouse.Update();

        Game.world.Update();
        Game.player.Update();
    }

    static Draw() {
        Game.world.Draw();
        Game.player.Draw();
    }

    static AddEventListeners() {
        window.addEventListener("resize", function () {
            canvas.width = innerWidth;
            canvas.height = innerHeight;
            gl.viewport(0, 0, innerWidth, innerHeight);
        });

        window.addEventListener("keydown", function (e) {
            if (e.repeat)
                return;
            Keyboard.OnKeyPress(e);
        });
        window.addEventListener("keyup", function (e) {
            if (e.repeat)
                return;
            Keyboard.OnKeyUp(e);
        });
        window.addEventListener("mousedown", (e) => {
            Mouse.OnMouseDown(e);
        });
        window.addEventListener("mouseup", (e) => {
            Mouse.OnMouseUp(e);
        });
        window.addEventListener("mousemove", (e) => {
            Mouse.OnMouseMove(e);
        });

        canvas.oncontextmenu = function (e) {
            e.preventDefault();
        };
    }
}