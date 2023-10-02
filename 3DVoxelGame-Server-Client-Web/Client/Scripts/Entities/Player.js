class Player extends Entity {
    movement_direction;

    speed = 10;
    Init() {
        this.movement_direction = new Vector3();
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
            this.movement_direction.z += Math.cos(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
        }
        if (Keyboard.IsKeyDown(87)) {
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
            this.movement_direction.z -= Math.cos(Mathf.ToRadians(this.rotation.y)) * this.speed * Time.delta_time;
        }
        if (Keyboard.IsKeyDown(65)) {
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y - 90)) * this.speed * Time.delta_time;
            this.movement_direction.z -= Math.cos(Mathf.ToRadians(this.rotation.y - 90)) * this.speed * Time.delta_time;
        }                                                                                 
        if (Keyboard.IsKeyDown(68)) {                                                     
            this.movement_direction.x += Math.sin(Mathf.ToRadians(this.rotation.y + 90)) * this.speed * Time.delta_time;
            this.movement_direction.z -= Math.cos(Mathf.ToRadians(this.rotation.y + 90)) * this.speed * Time.delta_time;
        }

        if (Keyboard.IsKeyDown(32)) {
            this.movement_direction.y += 0.2;
        }

        if (Keyboard.IsKeyDown(16)) {
            this.movement_direction.y -= 0.2;
        }

        if (this.movement_direction.GetMagnitude() > 0) {
            var closest_left = -1;
            var closest_right = 1;
            var closest_forwards = 1;
            var closest_backwards = -1
            var closest_up = 1;
            var closest_down = -1;
            var floored_x = Math.floor(this.position.x);
            var floored_y = Math.floor(this.position.y);
            var floored_z = Math.floor(this.position.z);

            if (this.movement_direction.x > 0) {
                for (var x = floored_x; x < floored_x + 5; x++) {
                    if (Game.world.GetBlock(x, this.position.y, this.position.z)) {
                        closest_right = Math.max(x - this.position.x - this.movement_direction.x - 0.05, 0);
                        break;
                    }
                }
            }
            else {
                for (var x = floored_x; x > floored_x - 5; x--) {
                    if (Game.world.GetBlock(x, this.position.y, this.position.z)) {
                        closest_left = -Math.abs((this.position.x - x) - 1 - 0.05);
                        break;
                    }
                }
            }
            this.position.x += Mathf.Clamp(this.movement_direction.x, closest_left, closest_right);

            if (this.movement_direction.z > 0) {
                for (var z = floored_z; z < floored_z + 5; z++) {
                    if (Game.world.GetBlock(this.position.x, this.position.y, z)) {
                        closest_forwards = Math.max(x - this.position.z - this.movement_direction.z - 0.05, 0);
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

            this.position.z += Mathf.Clamp(this.movement_direction.z, closest_backwards, closest_forwards);

            if (this.movement_direction.y > 0) {
                for (var y = floored_y; y < floored_y + 5; y++) {
                    if (Game.world.GetBlock(this.position.x, y, this.position.z)) {
                        closest_up = Math.max(y - this.position.y - this.movement_direction.y - 0.1, 0);
                        break;
                    }
                }
            }
            else {
                for (var y = floored_y; y > floored_y - 5; y--) {
                    if (Game.world.GetBlock(this.position.x, y, this.position.z)) {
                        closest_down = -Math.abs((this.position.y - y) - 1 - 0.1);
                        break;
                    }
                }
            }
            this.position.y += Mathf.Clamp(this.movement_direction.y, closest_down, closest_up);
        }


        this.rotation.y += Mouse.mouse_delta_x * 0.05;
        this.rotation.x += Mouse.mouse_delta_y * 0.05;

        this.rotation.x = Mathf.Clamp(this.rotation.x, -90, 90);

        var matrix = mat4.create();
        matrix = mat4.rotate(matrix, matrix, Mathf.ToRadians(this.rotation.x), [1, 0, 0]);
        matrix = mat4.rotate(matrix, matrix, Mathf.ToRadians(this.rotation.y), [0, 1, 0]);
        matrix = mat4.translate(matrix, matrix, [-this.position.x, -this.position.y, -this.position.z]);

        Game.chunk_shader.Start();
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.view_matrix_location, matrix);
        Game.chunk_shader.Stop();
    }
    Draw() {
    }
}