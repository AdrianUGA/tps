package fr.univ_lyon1.info.m1.balleauprisonnier_fx;


public class ComputerPlayer extends Player {

	ComputerPlayer(Team color, int xInit, int yInit, String side) {
		super(color, xInit, yInit, side);
		this.play(); // TODO check if the constructor really is the best place for this
	}

	private void play() {
		// TODO /dance
		
	}

	/* IA doesn't need this */
	@Override
	void event(String key) {}

}
