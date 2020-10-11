package fila;

public class Fila_Cliente {
	private No begin;
	private No end;

	public Fila_Cliente() {
		begin = null;
		end = null;
	}

	public void add(Cliente pessoa) {
		No add_novo = new No();

		add_novo.setPessoa(pessoa);

		if (begin == null) {
			begin = add_novo;
			end = add_novo;
			add_novo.setProx(null);
		} else {
			end.setProx(add_novo);
			end = add_novo;
			add_novo.setProx(null);
		}

	}

	public void remover() {
		if (begin == null) {
			System.out.println("Fila vazia");
			return;
		}
		
		begin = begin.getProx();
	}

	public void show() {
		No mostrar = begin;
		if (begin == null) {
			System.out.println("Fila vazia");
			return;
		}

		while (mostrar != null) {
			System.out.println("Name: " + mostrar.getPessoa().getName());
			mostrar = mostrar.getProx();
		}
	}
}
