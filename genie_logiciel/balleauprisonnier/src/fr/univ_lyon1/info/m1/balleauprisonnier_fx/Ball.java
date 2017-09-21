package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

public class Ball {
	private Position position;
	private double step;
	
	/* Angle between the vertical axe and the direction. Clockwise. */
	private double angle;
	
	public void move() {
		position.move(angle, step);
	}
}
