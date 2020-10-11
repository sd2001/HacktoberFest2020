package listaencadeada;

public class Library {
	private Book inicio;
	private Book fim;

	public Library() {
		inicio = null;
		fim = null;
	}

	public void add_Book(Book li) {
		Book livros;

		livros = li;

		// Não tem nenhum elemento
		if (inicio == null) {

			inicio = livros;
			fim = livros;

		} else {
			fim.setProximo(livros);
			fim = livros;
		}

	}

	public void removeElement(String nameBook) {
		Book aux = inicio;
		Book ant = null;

		if (inicio == null) {
			System.out.println("Lista vazia...");
			return;
		}

		while (aux != null) {

			if (aux.getName() == nameBook) {

				if (aux == inicio) {
					inicio = aux.getProximo();
					aux = null;
				} else if (aux == fim) {
					fim = ant;
					ant.setProximo(null);
					aux = null;
				} else {
					ant.setProximo(aux.getProximo());
					aux = null;
				}

				return;
			}

			ant = aux;
			aux = aux.getProximo();
		}
	}

	public String search(String nameBook) {
		Book aux = inicio;

		if (inicio == null) {
			return "Lista vazia...";
		}

		while (aux != null) {

			if (aux.getName() == nameBook) {
				return aux.getName();
			}

			aux = aux.getProximo();
		}

		return "Livro nao encontrado";
	}

	public void showList() {
		Book aux = inicio;

		if (inicio == null) {
			System.out.println("Lista vazia...");
			return;
		}

		while (aux != null) {

			System.out.println("Nome: " + aux.getName() + " Autor: " + aux.getAuthor());
			aux = aux.getProximo();
		}
	}
}
