package fr.univ_lyon1.info.m1.balleauprisonnier_fx;


/**
 * 
 * Classe gerant un joueur
 *
 */
abstract public class Player implements PlayerInterface {
	private static final int DEFAULT_ANGLE = 0;

	Position position;
	double angle = 90; // rotation du joueur, devrait toujour être en 0 et 180
	double step; // pas d'un joueur
	Team team;
	Side side;

	boolean hasBall;

	/**
	 * Constructeur du Joueur
	 * 
	 * @param gc
	 *            ContextGraphic dans lequel on va afficher le joueur
	 * @param team
	 *            couleur du joueur
	 * @param yInit
	 *            position verticale
	 */
	Player(Team team, Position position, Side side, double step) {
		this.team = team;
		this.position = position;
		this.angle = DEFAULT_ANGLE;
		this.step = step;
		this.side = side;
		this.hasBall = false;
	}

	

	/**
	 * Deplacement du joueur
	 */
	public void move(Direction direction) {
		this.position.move(direction, this.step);
	}

	/**
	 * Rotation du joueur vers la gauche
	 */
	public void turnLeft() {
		if (angle > 0 && angle < 180)
			angle += 1;
		else
			angle += 1;
	}

	/**
	 * Rotation du joueur vers la droite
	 */
	public void turnRight() {
		if (angle > 0 && angle < 180)
			angle -= 1;
		else
			angle -= 1;
	}

	public void shoot() {
		
	}

	/**
	 * Deplacement en mode boost
	 */
	public void boost() {
		step *= 2;
	}

	public double getStep() {
		return step;
	}

	public void setStep(double step) {
		this.step = step;
	}

	public abstract void event(String key);

	@Override
	public String toString() {
		return "Player [position=" + position + ", angle=" + angle + ", team=" + team + "]";
	}

	public Position getPosition() {
		return this.position;
	}

	public Side getSide() {
		return this.side;
	}
	
	public double getAngle() {
		return this.angle;
	}
	
	public void setHasBall(boolean b) {
		this.hasBall = b;
	}

}
