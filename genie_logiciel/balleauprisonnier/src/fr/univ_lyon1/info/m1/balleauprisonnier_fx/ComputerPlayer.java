package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import javafx.scene.canvas.GraphicsContext;

public class ComputerPlayer extends Player {

	ComputerPlayer(GraphicsContext gc, String color, int xInit, int yInit, String side) {
		super(gc, color, xInit, yInit, side);
		this.play(); // TODO check if the constructor really is the best place for this
	}

	private void play() {
		// TODO /dance
		
	}

	/* IA doesn't need this */
	@Override
	void event(String key) {}

}
