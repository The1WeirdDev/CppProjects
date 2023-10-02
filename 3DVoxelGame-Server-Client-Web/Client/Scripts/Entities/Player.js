class Player extends Entity {
    movement_direction;
    velocity = 0;
    gravity = -20.81;

    speed = 10;

    is_grounded = false;
    Init() {
        this.movement_direction = new Vector2();
        this.position.y = 20;

        canvas.addEventListener("click", async () => {
            await canvas.requestPointerLock({
                unadjustedMovement: true,
            });

            document.addEventListener("pointerlockchange", (e) => {
                cursor_locked = document.pointerLockElement != null;
            }, false);
        });
        document.body.style.cursor = 'none';
    }

    Update() {
        if (cursor_locked == false)
            return;

        this.movement_direction = new Vector3();

        if (Keyboard.IsKeyDown(83)) {
            this.movement_direction.x -= Math.sin(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
            this.movement_direction.y += Math.cos(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
        }
        if (Keyboard.IsKeyDown(87)) {
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
            this.movement_direction.y -= Math.cos(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
        }
        if (Keyboard.IsKeyDown(65)) {
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y - 90)) * this.speed * Time.delta_time;
            this.movement_direction.y -= Math.cos(Mathf.ToRadians(this.rotation.y - 90)) * this.speed * Time.delta_time;
        }                                                                                 
        if (Keyboard.IsKeyDown(68)) {                                                     
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y + 90)) * this.speed * Time.delta_time;
            this.movement_direction.y -= Math.cos(Mathf.ToRadians(this.rotation.y + 90)) * this.speed * Time.delta_time;
        }

        this.velocity += this.gravity * Time.delta_time;
        
        if (Keyboard.IsKeyDown(16)) {

        }
        var floored_y = Math.floor(this.position.y);
        var floored_z = Math.floor(this.position.z);

        if (this.movement_direction.GetMagnitude() > 0) {
            var closest_left = -1;
            var closest_right = 1;
            var closest_forwards = 1;
            var closest_backwards = -1

            var left_floored_x = Math.floor(this.position.x + 0.2);
            var right_floored_x = Math.floor(this.position.x - 0.2);
            if (this.movement_direction.x > 0) {
                for (var x = left_floored_x; x < left_floored_x + 5; x++) {
                    if (Game.world.GetBlock(x, this.position.y, this.position.z)) {
                        closest_right = Math.max(x - this.position.x - this.movement_direction.x - 0.05, 0);
                        break;
                    }
                }
            }
            else {
                for (var x = right_floored_x; x > right_floored_x - 5; x--) {
                    if (Game.world.GetBlock(x, this.position.y, this.position.z)) {
                        closest_left = -Math.abs((this.position.x - x) - 1 - 0.05);
                        break;
                    }
                }
            }
            if ((closest_left < 0 && this.movement_direction.x < 0) || (closest_right > 0 && this.movement_direction.x > 0))
                this.position.x += Mathf.Clamp(this.movement_direction.x, closest_left, closest_right);

            if (this.movement_direction.y > 0) {
                for (var z = floored_z; z < floored_z + 5; z++) {
                    if (Game.world.GetBlock(this.position.x, this.position.y, z)) {
                        closest_forwards = Math.max(x - this.position.z - this.movement_direction.y - 0.05, 0);
                        break;
                    }
                }
            }
            else {
                for (var z = floored_z; z > floored_z - 5; z--) {
                    if (Game.world.GetBlock(this.position.x, this.position.y, z)) {
                        closest_backwards = -Math.abs((this.position.z - z) - 1 - 0.05);
                        break;
                    }
                }
            }

            if ((closest_backwards < 0 && this.movement_direction.y < 0) || (closest_forwards > 0 && this.movement_direction.y > 0))
                this.position.z += Mathf.Clamp(this.movement_direction.y, closest_backwards, closest_forwards);

        }
        var closest_up = 1;
        var closest_down = -1;
        var movement_velocity = this.velocity * Time.delta_time;
        if (this.velocity != 0) {
            for (var y = floored_y; y < floored_y + 5; y++) {
                if (Game.world.GetBlock(this.position.x, y, this.position.z)) {
                    closest_up = Math.max(y - this.position.y - movement_velocity - 0.5, 0);
                    break;
                }
            }
            for (var y = floored_y; y > floored_y - 5; y--) {
                if (Game.world.GetBlock(this.position.x, y, this.position.z)) {
                    closest_down = -Math.abs((this.position.y - y) - 1 - 0.25);
                    break;
                }
            }
        }
        this.is_grounded = false;
        if (closest_down > -0.05) {
            if (Keyboard.IsKeyDown(32)) {
                this.velocity = Math.sqrt(5.0 * -2.0 * this.gravity);
                movement_velocity = this.velocity * Time.delta_time;
            } else {
                this.is_grounded = true;
                this.velocity = 0;
                movement_velocity = 0;
            }
        }
        if (((closest_down < 0 && movement_velocity < 0) || (closest_up > 0 && movement_velocity > 0)) && Game.world.GetBlock(this.position.x, this.position.y, this.position.z) == 0)
            this.position.y += Mathf.Clamp(movement_velocity, closest_down, closest_up);
        else {
            this.is_grounded = true;
            this.velocity = 0;
        }
        this.GetMouseInput();
        this.CalculateMatrices();
    }
    Draw() {
    }

    GetMouseInput() {
        this.rotation.y += Mouse.mouse_delta_x * 0.05;
        this.rotation.x += Mouse.mouse_delta_y * 0.05;

        this.rotation.x = Mathf.Clamp(this.rotation.x, -90, 90);
    }

    CalculateMatrices() {
        var matrix = mat4.create();
        matrix = mat4.rotate(matrix, matrix, Mathf.ToRadians(this.rotation.x), [1, 0, 0]);
        matrix = mat4.rotate(matrix, matrix, Mathf.ToRadians(this.rotation.y), [0, 1, 0]);
        matrix = mat4.translate(matrix, matrix, [-this.position.x, -this.position.y, -this.position.z]);

        Game.chunk_shader.Start();
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.view_matrix_location, matrix);
        Game.chunk_shader.Stop();
    }
}