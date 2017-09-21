package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.transform.Rotate;
import javafx.util.Duration;

/*
 * Proxy pattern
 * We act as a transparent object proxiing a Player. As we intercept actions, we can act on the graphical interface
 */
public class GraphicPlayer implements PlayerInterface {
	Image directionArrow;
	Sprite sprite;
	ImageView PlayerDirectionArrow;
	GraphicsContext gc;

	/*
	 * This class refer to a player instead to inherit it in order to handle
	 * graphics for any type of Player in a single class
	 */
	private Player player;

	public GraphicPlayer(GraphicsContext gc, Player player) {
		this.gc = gc;
		this.player = player;
		
		// On charge la representation du joueur
		if (player.getSide() == Side.TOP) {
			directionArrow = new Image("assets/PlayerArrowDown.png");
		} else {
			directionArrow = new Image("assets/PlayerArrowUp.png");
		}

		PlayerDirectionArrow = new ImageView();
		PlayerDirectionArrow.setImage(directionArrow);
		PlayerDirectionArrow.setFitWidth(10);
		PlayerDirectionArrow.setPreserveRatio(true);
		PlayerDirectionArrow.setSmooth(true);
		PlayerDirectionArrow.setCache(true);

		Image tilesheetImage = new Image("assets/orc.png");
		sprite = new Sprite(tilesheetImage, 0, 0, Duration.seconds(.2), this.player.getSide());
		sprite.setX(player.getPosition().getX());
		sprite.setY(player.getPosition().getY());
		// directionArrow = sprite.getClip().;
		
		this.display();
		this.spriteAnimate();
	}
	
	@Override
	public void shoot() {
		sprite.playShoot();
		this.player.shoot();
	}

	void spriteAnimate() {
		// System.out.println("Animating sprite");
		if (!sprite.isRunning) {
			sprite.playContinuously();
		}
		sprite.setX(this.player.getPosition().getX());
		sprite.setY(this.player.getPosition().getY());
	}

	@Override
	public void boost() {
		this.player.boost();
		spriteAnimate();
	}

	private void rotate(GraphicsContext gc, double angle, double px, double py) {
		Rotate r = new Rotate(angle, px, py);
		gc.setTransform(r.getMxx(), r.getMyx(), r.getMxy(), r.getMyy(), r.getTx(), r.getTy());
	}

	public void display() {
		this.gc.save(); // saves the current state on stack, including the current transform
		this.rotate(this.gc, this.player.getAngle(), this.player.getPosition().getX() + directionArrow.getWidth() / 2,
				this.player.getPosition().getY() + directionArrow.getHeight() / 2);
		this.gc.drawImage(directionArrow, this.player.getPosition().getX(), this.player.getPosition().getY());
		this.gc.restore(); // back to original state (before rotation)
	}

	@Override
	public void move(Direction direction) {
		this.player.move(direction);
		this.spriteAnimate();
	}

	@Override
	public void turnLeft() {
		this.player.turnLeft();
	}

	@Override
	public void turnRight() {
		this.player.turnRight();
	}

	@Override
	public double getStep() {
		return this.player.getStep();
	}

	@Override
	public void setStep(double step) {
		this.player.setStep(step);

	}

	@Override
	public void event(String key) {
		this.player.event(key);
		this.display();
		this.spriteAnimate();
	}

	@Override
	public Position getPosition() {
		return this.player.getPosition();
	}

	@Override
	public Side getSide() {
		return this.player.getSide();
	}

	@Override
	public double getAngle() {
		return this.player.getAngle();
	}
}
