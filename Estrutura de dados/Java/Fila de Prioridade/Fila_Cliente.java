package fila;

public class Fila_Cliente {
	private No begin;
	private No end;

	public Fila_Cliente() {
		begin = null;
		end = null;
	}

	public void add(Cliente pessoa) {
		No no = new No();

		no.setPessoa(pessoa);

		if (begin == null) {
			begin = no;
			end = no;
			no.setProx(null);
		} else {
			// Se a pessoa tiver mais de 69 anos sera prioridade

			if (no.getPessoa().getAge() > 69) {
				no.setProx(begin);
				begin = no;
			} else {
				end.setProx(no);
				end = no;
				no.setProx(null);
			}
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
