package fr.univ_lyon1.info.m1.balleauprisonnier_fx;


public class ComputerPlayer extends Player {

	ComputerPlayer(Team color, Position position, Side side, double step) {
		super(color, position, side, step);
		this.play(); // TODO check if the constructor really is the best place for this
	}

	private void play() {
		// TODO /dance
		
	}

	/* IA doesn't need this */
	@Override
	public void event(String key) {}

}
