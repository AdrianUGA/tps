package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.LinkedList;
import java.util.List;

import javafx.animation.AnimationTimer;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

/**
 * Classe gerant le terrain de jeu.
 * 
 */
public class Field extends Canvas {

	final GraphicsContext gc;
	final int width;
	final int height;
	final Game game;

	/**
	 * Canvas dans lequel on va dessiner le jeu.
	 * 
	 * @param scene
	 *            Scene principale du jeu a laquelle on va ajouter notre Canvas
	 * @param w
	 *            largeur du canvas
	 * @param h
	 *            hauteur du canvas
	 */
	public Field(Scene scene, int w, int h) {
		super(w, h);

		List<Player> players = new LinkedList<Player>();

		String[] player1 = { "UP", "DOWN", "LEFT", "RIGHT", "SPACE" };
		players.add(new HumanPlayer(Team.RED, w / 2, h - 150, "bottom", player1));
		players.add(new ComputerPlayer(Team.RED, w / 3, h - 100, "bottom"));
		players.add(new ComputerPlayer(Team.RED, w - w / 3, h - 100, "bottom"));

		String[] player2 = { "Z", "S", "Q", "D", "R" };
		players.add(new HumanPlayer(Team.BLUE, w / 2, 50, "top", player2));
		players.add(new ComputerPlayer(Team.BLUE, w / 3, 20, "top"));
		players.add(new ComputerPlayer(Team.BLUE, w - w / 3, 20, "top"));

		game = new Game(players);
		width = w;
		height = h;

		/** permet de capturer le focus et donc les evenements clavier et souris */
		this.setFocusTraversable(true);

		gc = this.getGraphicsContext2D();

		/** On initialise le terrain de jeu */

		/**
		 * Event Listener du clavier quand une touche est pressee on la rajoute a la
		 * liste d'input
		 * 
		 */
		this.setOnKeyPressed(new EventHandler<KeyEvent>() {
			public void handle(KeyEvent e) {
				String code = e.getCode().toString();
				// only add once... prevent duplicates
				if (!game.input.contains(code))
					game.input.add(code);
			}
		});

		/**
		 * Event Listener du clavier quand une touche est relachee on l'enleve de la
		 * liste d'input
		 * 
		 */
		this.setOnKeyReleased(new EventHandler<KeyEvent>() {
			public void handle(KeyEvent e) {
				String code = e.getCode().toString();
				game.input.remove(code);
			}
		});

		/**
		 * 
		 * Boucle principale du jeu
		 * 
		 * handle() est appelee a chaque rafraichissement de frame soit environ 60 fois
		 * par seconde.
		 * 
		 */
		new AnimationTimer() {

			public void handle(long currentNanoTime) {
				// On nettoie le canvas a chaque frame
				gc.setFill(Color.LIGHTGRAY);
				gc.fillRect(0, 0, width, height);

				// Deplacement et affichage des joueurs
				for (Player player : game.getJoueurs()) {
					for (String in : game.input) {
						player.event(in);
					}
					gc.save(); // saves the current state on stack, including the current transform
					player.rotate(gc, player.angle, player.x + player.directionArrow.getWidth() / 2,
							player.y + player.directionArrow.getHeight() / 2);
					gc.drawImage(player.directionArrow, player.x, player.y);
					gc.restore(); // back to original state (before rotation)
				}
			}
		}.start(); // On lance la boucle de rafraichissement
	}

}
