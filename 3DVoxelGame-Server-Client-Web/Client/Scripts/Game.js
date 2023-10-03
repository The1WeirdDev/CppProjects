class Game {
    static player = null;
    static shader = null;
    static chunk_shader = null;
    static non_local_player_shader = null;
    static world = null;

    static Init() {
        Display.Init();
        Keyboard.Init();
        Mouse.Init();

        Game.shader = new Shader();
        Game.shader.Create(`precision mediump float;\nattribute vec2 position; void main(){gl_Position = vec4(position, 0.0, 1.0);}`,
            `precision mediump float;\nvoid main(){gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);}`);

        Game.chunk_shader = new ChunkShader();
        //Game.non_local_player_shader = new NonLocalPlayerShader();

        Game.world = new ServerWorld();
        Game.world.Init();

        Game.player = new LocalPlayer();
        Game.player.Init();

        canvas.width = innerWidth;
        canvas.height = innerHeight;
        gl.viewport(0, 0, innerWidth, innerHeight);

        Game.AddEventListeners();
        Game.CreateAndLoadProjectionMatrix();

        Networking.Init();
        Time.Init();
    }

    static Update() {
        Display.Update();
        Keyboard.Update();
        Mouse.Update();
        Time.Update();

        Game.world.Update();
        Game.player.Update();
    }

    static Draw() {
        Game.world.Draw();
        //Networking.Draw();
        //Game.player.Draw();
        //Frustom.IsPointInsideViewFrustom(0, 0, 0, Game.player.view_matrix);
    }

    static CreateAndLoadProjectionMatrix() {
        Game.chunk_shader.Start();
        var matrix1 = mat4.create();
        matrix1 = mat4.perspective(matrix1, Mathf.ToRadians(75), Display.GetAspectRatio(), 0.001, 1000);
        //mat4.translate(matrix1, matrix1, [0, 0, 0.5])
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.projection_matrix_location, matrix1);
        Game.chunk_shader.Stop();

        //Game.non_local_player_shader.Start();
        //Game.non_local_player_shader.LoadProjectionMatrix(matrix2);
        //Game.non_local_player_shader.Stop();
    }

    static AddEventListeners() {
        window.addEventListener("resize", function () {
            canvas.width = innerWidth;
            canvas.height = innerHeight;
            gl.viewport(0, 0, innerWidth, innerHeight);

            Game.CreateAndLoadProjectionMatrix();
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
            const {
                movementX,
                movementY
            }= e;
            movement_x = movementX;
            movement_y = movementY;
            Mouse.OnMouseMove(e);
        });


        canvas.oncontextmenu = function (e) {
            e.preventDefault();
        };
    }
}