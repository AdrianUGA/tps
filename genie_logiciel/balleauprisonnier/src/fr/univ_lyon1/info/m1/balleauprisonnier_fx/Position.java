package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

public class Position {
	private double x; // position horizontale du joueur
	private final double y; // position verticale du joueur
	
	public static double maxX;

	public Position(double x, double y) {
		super();
		this.x = x;
		this.y = y;
	}

	public void move(Direction direction, double step) {
		switch (direction) {
		case NORTH:
			System.err.println("Moving up is not allowed");
			break;
		case EAST:
			if (x > 10 && x < maxX)
				this.x += step;
			break;
		case SOUTH:
			System.err.println("Moving down is not allowed");
			break;
		case WEST:
			if (x > 10 && x < maxX)
				this.x -= step;
			break;
		default:
			System.err.println("Moving to this direction is not supported : "+direction);
			break;
		}
	}

	public void move(double angle, double step) {
		// todo some calculations
		
	}


	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	@Override
	public String toString() {
		return "Position [x=" + x + ", y=" + y + "]";
	}

}
