package fila;

public class Fila {

	public static void main(String[] args) {
		Fila_Cliente fila = new Fila_Cliente(); // Fila onde os clientes estão

		Cliente pessoa1 = new Cliente("Jair", 19);
		Cliente pessoa2 = new Cliente("Francisco", 29);
		Cliente pessoa3 = new Cliente("Oliveira", 29);
		Cliente pessoa4 = new Cliente("Brunce", 29);
		Cliente pessoa5 = new Cliente("Stark", 29);

		fila.add(pessoa2);
		fila.add(pessoa1);
		fila.add(pessoa3);
		fila.add(pessoa4);
		fila.add(pessoa5);

		fila.show();

		fila.remover();
		fila.remover();
		fila.remover();
		fila.remover();
		fila.remover();

		System.out.println("------------------");
		fila.show();
	}

}
