package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.List;

public class Game {
	/** Joueurs */
	List<PlayerInterface> players;
	
	final int width;
	final int height;
	BallInterface ball;
    
    public Game(List<PlayerInterface> players2, int width, int height) {
    	this.players = players2;
    	this.width = width;
    	this.height = height;
    }
    
	public List<PlayerInterface> getJoueurs() {
		return this.players;
	}

	public List<PlayerInterface> getPlayers() {
		return players;
	}

	public void setPlayers(List<PlayerInterface> players) {
		this.players = players;
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public BallInterface getBall() {
		return this.ball;
	}
	
	public void setBall(BallInterface ball)  {
		this.ball = ball;
	}

	public void playFrame() {
		this.ball.move();
		if(this.ball.isStopped()) {
			if(this.ball.getPosition().getY() > this.width/2)
				this.pickupBall(Side.BOTTOM);
			else
				this.pickupBall(Side.TOP);
		}
		
	}

	private void pickupBall(Side side) {
		for(PlayerInterface player : this.players) {
			if(player.getSide() == side) {
				player.setHasBall(true);
				break;
			}
		}
	}
	
	
}
