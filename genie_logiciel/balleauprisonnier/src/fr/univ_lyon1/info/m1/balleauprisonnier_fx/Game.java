package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Game {
	/** Joueurs */
	List<Player> players = new LinkedList<Player>();
	
	/** Tableau traçant les evenements */
    ArrayList<String> input = new ArrayList<String>();
    
    public Game(List<Player> players) {
    	this.players = players;
    }
    
	public List<Player> getJoueurs() {
		return this.players;
	}
}
