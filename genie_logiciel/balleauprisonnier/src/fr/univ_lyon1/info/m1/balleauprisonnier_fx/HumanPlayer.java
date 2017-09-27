package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class HumanPlayer extends Player {
	static final String SHOOT = "shoot";
	static final String TURN_LEFT = "turnLeft";
	static final String TURN_RIGHT = "turnRight";
	static final String MOVE_LEFT = "moveLeft";
	static final String MOVE_RIGHT = "moveRight";
	
	private Map<String, String> keys;

	
	HumanPlayer(Team team, Position position, Side side, double step, Map<String, String> keys) {
		super(team, position, side, step);
		this.keys = keys;
	}
	
	HumanPlayer(Team team, Position position, Side side, double step, String[] keys){
		super(team, position, side, step);
		this.setKeys(keys);
	}



	public void event(String key) {
		if(this.keys.containsKey(key)) {
			switch(this.keys.get(key)) {
				case MOVE_RIGHT:
					this.move(Direction.EAST);
					break;
				case MOVE_LEFT:
					this.move(Direction.WEST);
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


	public void setKeys(String[] keys) {
		String[] actions = {HumanPlayer.TURN_LEFT, HumanPlayer.TURN_RIGHT, HumanPlayer.MOVE_LEFT, HumanPlayer.MOVE_RIGHT, HumanPlayer.SHOOT};
		Iterator<String> i1 = Arrays.asList(actions).iterator();
		Iterator<String> i2 = Arrays.asList(keys).iterator();
		this.keys = new HashMap<String, String>();
		while (i1.hasNext() && i2.hasNext()) this.keys.put(i2.next(), i1.next());
	}

}
