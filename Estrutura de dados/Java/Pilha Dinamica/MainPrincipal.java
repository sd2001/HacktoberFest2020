package library;

public class MainPrincipal {

	public static void main(String[] args) {
		Biblioteca bib = new Biblioteca();

		bib.push(new Livro("jair", "JJ", 123));
		bib.push(new Livro("jair1", "JJ", 123));

		// bib.push(new Livro("jair3", "JJ", 123));

		// bib.show();
		bib.topoShow();
		bib.pop();
		bib.push(new Livro("jair2", "JJ", 123));
		// bib.pop();
		bib.topoShow();
	}

}
