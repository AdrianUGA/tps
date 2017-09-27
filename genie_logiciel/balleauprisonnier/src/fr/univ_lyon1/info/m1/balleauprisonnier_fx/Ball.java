package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

public class Ball implements BallInterface {
	private Position position;
	private double step;
	
	/* Angle between the vertical axe and the direction. Clockwise. */
	private double angle;
	
	@Override
	public void move() {
		position.move(angle, step);
		step--;
	}

	@Override
	public boolean isStopped() {
		return step == 0;
	}
}
