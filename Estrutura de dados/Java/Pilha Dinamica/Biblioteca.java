package library;

public class Biblioteca {
	private No topo;

	public Biblioteca() {
		topo = null;
	}

	public boolean empty() {
		if (topo == null) {
			return true;
		}

		return false;
	}

	public void push(Livro book) {
		No novo = new No();

		novo.setBooks(book);
		novo.setProx(topo);// novo->prox = topo
		topo = novo;
		/* o novo elemento vai para o "proximo do topo" e um novo topo e selecionando */
	}

	public void show() {
		No aux = topo;

		while (aux != null) {
			System.out.println("Nome: " + aux.getBooks().getNameBook());
			aux = aux.getProx();
		}
	}

	public void topoShow() {
		System.out.printf("O Topo: %s\n", topo.getBooks().getNameBook());
	}

	public void pop() {
		if (empty()) {
			System.out.println("Pilha vazia");
		} else {
			topo = topo.getProx();
		}
	}
}
