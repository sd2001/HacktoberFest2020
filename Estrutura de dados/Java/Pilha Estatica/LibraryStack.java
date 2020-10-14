package biblioteca;

public class LibraryStack {
	private Livro livros[];
	private int tamanho_MAX;
	private int topo;

	public LibraryStack(int max) {
		tamanho_MAX = max;
		livros = new Livro[tamanho_MAX];
		topo = -1;
	}

	public boolean cheio() {
		if (tamanho_MAX == topo) {
			return true;
		}

		return false;
	}

	public void push(Livro l) {

		if (!cheio()) {
			topo++;
			livros[topo] = l;
		} else {
			System.out.println("Pilha Cheia");
		}
	}

	public void showStack() {
		if (topo == -1) {
			System.out.println("Pilha vazia");
		} else {
			for (int i = 0; i <= topo; i++) {
				System.out.println("Nome: " + livros[i].getNameBook());
			}
		}
	}

	public Livro topoStack() {
		return livros[topo];
	}

	public void pop() {
		if (topo == -1) {
			System.out.println("Pilha vazia");
		} else {
			topo--;
		}
	}
}
