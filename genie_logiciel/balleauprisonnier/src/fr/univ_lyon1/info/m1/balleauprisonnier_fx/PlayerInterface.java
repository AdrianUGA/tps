package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

public interface PlayerInterface {

	/**
	 * Deplacement du joueur
	 */
	void move(Direction direction);

	/**
	 * Rotation du joueur vers la gauche
	 */
	void turnLeft();

	/**
	 * Rotation du joueur vers la droite
	 */
	void turnRight();

	void shoot();

	void boost();

	public double getStep();
	public void setStep(double step);

	public abstract void event(String key);

	public Position getPosition();

	public Side getSide();
	
	public double getAngle();

	void setHasBall(boolean b);

}
