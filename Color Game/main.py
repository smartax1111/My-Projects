import arcade

SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480


class Stick(arcade.Sprite):
    def __init__(self, pos_x, width, color):
        super().__init__()
        self.pos_x = pos_x
        self.width = width
        self.color = color

    def draw(self):
        arcade.draw_rectangle_filled(self.pos_x, 40, self.width, 20, self.color)


class Ball(arcade.Sprite):
     def update(self):
        self.center_y -= 1


class Game(arcade.Window):
    isRunning = False

    def __init__(self, width, height, title):
        super().__init__(width, height, title)
        self.set_mouse_visible(False)

        self.score = 0

        arcade.set_background_color(arcade.color.ASH_GREY)
        self.stick = Stick(SCREEN_WIDTH - 50, 100, arcade.color.WHITE)


    def on_draw(self):
        arcade.start_render()


    def on_mouse_motion(self, x, y, dx, dy):
        self.stick.pos_x = x
        if not self.isRunning:
            self.ball.pos_x = x

    def on_mouse_press(self, x, y, button, modifiers):
        self.isRunning = True



def main():
    window = Game(640, 480, "Pong")
    arcade.run()


main()
