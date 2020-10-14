package pilha;

public class Stack {
	public Pessoa topo;

	public Stack() {
		topo = null;
	}

	public void push(String nome) {
		Pessoa person = new Pessoa();

		person.nome = nome;

		if (topo == null) {

			person.proximo = null;

			topo = person;
		} else {
			person.proximo = topo; // Vai apontar para o topo antigo
			topo = person; // O novo topo e selecionando
		}
	}

	public String topoShow() {
		if (topo != null) {
			return topo.nome;
		}

		return "Pilha Vazia";
	}

	public void pop() {
		topo = topo.proximo;
	}
}
