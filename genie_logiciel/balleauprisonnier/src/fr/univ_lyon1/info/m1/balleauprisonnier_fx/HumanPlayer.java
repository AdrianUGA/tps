package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.Map;

import javafx.scene.canvas.GraphicsContext;

public class HumanPlayer extends Player {
	static final String SHOOT = "shoot";
	static final String TURN_LEFT = "turnLeft";
	static final String TURN_RIGHT = "turnRight";
	static final String MOVE_LEFT = "moveLeft";
	static final String MOVE_RIGHT = "moveRight";
	
	private Map<String, String> keys;

	
	HumanPlayer(GraphicsContext gc, String color, int xInit, int yInit, String side, Map<String, String> keys) {
		super(gc, color, xInit, yInit, side);
		this.keys = keys;
	}
	
	public void event(String key) {
		if(this.keys.containsKey(key)) {
			switch(this.keys.get(key)) {
				case MOVE_RIGHT:
					this.moveRight();
					break;
				case MOVE_LEFT:
					this.moveLeft();
					break;
				case TURN_RIGHT:
					this.turnRight();
					break;
				case TURN_LEFT:
					this.turnLeft();
					break;
				case SHOOT:
					this.shoot();
					break;
			}
		}
	}

	public Map<String, String> getKeys() {
		return keys;
	}


	public void setKeys(Map<String, String> keys) {
		this.keys = keys;
	}

}
