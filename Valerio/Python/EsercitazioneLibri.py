from datetime import date
from random import randint, getrandbits

class Libro:
    def __init__(self, titolo, anno_pubblicazione, ):
        self.__titolo = titolo
        self.__anno_pubblicazione = anno_pubblicazione

    def visualizza(self):
        print(f"Titolo: {self.titolo}\nAnno di pubblicazione: {self.anno_pubblicazione}")

    @property
    def titolo(self):
        return self.__titolo

    @property
    def anno_pubblicazione(self):
        return self.__anno_pubblicazione

class Moderno(Libro):
    def __init__(self, titolo, anno_pubblicazione, costo):
        super().__init__(titolo, anno_pubblicazione)
        self.__costo = costo

    def valore(self):
        return self.__costo * .75 + 3000 - self.anno_pubblicazione

    def visualizza(self):
        super().visualizza()
        print("Prezzo: %.2f€" % self.valore())

class Antico(Libro):
    def __init__(self, titolo, anno_pubblicazione, stampato):
        super().__init__(titolo, anno_pubblicazione)
        self.__stampato = stampato

    def valore(self):
        return (3000 - self.anno_pubblicazione) * 2.5 + (1000 if self.__stampato else 0)

    def visualizza(self):
        super().visualizza()
        print("Prezzo: %.2f€" % self.valore())

class Biblioteca:
    def __init__(self, n):
        nomiMod = ["Profezie. Che cosa ci riserva il futuro", "Harry Potter e la pietra filosofale.",
                "Storia di chi fugge e di chi resta. L'amica geniale.",
                "Storia della bambina perduta. L'amica geniale.",
                "In cucina con voi! Tutte le nuove ricette di «Fatto in casa da Benedetta»",
                "Harry Potter e la camera dei segreti.", "Storia del nuovo cognome. L'amica geniale.",
                "Harry Potter e il prigioniero di Azkaban.", "L'amica geniale.", "Harry Potter e il calice di fuoco.",
                "Harry Potter e il prigioniero di Azkaban.", "Harry Potter e l'Ordine della Fenice.",
                "Harry Potter e il Principe Mezzosangue.", "Cecità", "Respira", "La misura del tempo",
                "La casa delle voci", "Le fantafiabe di Luì e Sofì", "Harry Potter e il calice di fuoco.",
                "Harry Potter e i doni della morte.", "Mancherai all'infinito", "Io, te e il mare",
                "Le corna stanno bene su tutto. Ma io stavo meglio senza!", "La fiamma nel buio",
                "Harry Potter e l'Ordine della Fenice.", "I leoni di Sicilia. La saga dei Florio", "1984",
                "Fatto in casa da Benedetta. Torte, primi sfiziosi, stuzzichini... le ricette più golose del web.",
                "Harry Potter e il Principe Mezzosangue.", "La profezia dell'armadillo. Artist edition",
                "Harry Potter e i doni della morte.", "L'arte di essere fragili. Come Leopardi può salvarti la vita",
                "L'insostenibile leggerezza dell'essere", "Una gran voglia di vivere",
                "La verità sul caso Harry Quebert", "Gli scomparsi di Chiardiluna. L'Attraversaspecchi.", "1984",
                "Shantaram", "The Mamba mentality. Il mio basket", "Aria",
                "La cucina di casa mia. Le nuove ricette di «Fatto in casa da Benedetta»",
                "Harry Potter e la maledizione dell'erede. Parte uno e due. Scriptbook. Ediz. speciale",
                "Norwegian wood. Tokyo blues", "Fragile. La mia storia", "La vita bugiarda degli adulti",
                "La memoria di Babel. L'Attraversaspecchi.", "Kafka sulla spiaggia", "Finché il caffè è caldo"]
        nomiAnt = ["Noctes Atticae", "De veteri ritu nuptiarum et jure connubiorum", "De rebus gestis Alexandri Magni historia", "L'unione e non l'unità d'Italia per Pietro C. Ullo…di Favale e Rotondella. Seconda edizione italiana", "Don Chisciotte illustrato da Gustave Doré", "[Decretales]", "Della consolatione de la filosofia, tradotto da Cosimo Bartoli, gentil'huomo fiorentino", "Disputationum de nuptiis libri VII", "Quae exstant opera", "I tre moschettieri", "Al di là del bene e del male. Preludio d'una filos…'avvenire. Versione dal tedesco di Edmondo Weisel", "Cathena aurea angelici Thome Aquinatis in quatuor …o concinnata iussu summi ponteficis Urbani Quarti", "Orationi militari, raccolte da tutti gli historici greci, e latini; antichi e moderni", "De rebus publicis Hanseaticis. Tractatus generalis et specialis", "Trattato de' mali dell'ossa, in cui si rappresenta…e le macchine, che convengono alla lor guarigione", "Gli amici. Edizione ridotta e riveduta dall'Autore…te Paolocci, Ettore Ximenes, Giuseppe Pennasilico", "Il lupo della steppa", "Annotationes... in quatuor et viginti Pandectarum libros", "Aurea practica criminalis ex recognitione Arnoldi Baert", "De mare libero", "Discorso sopra l'asilo ecclesiastico", "Scene della vita parigina", "La beccaccia. Anatomia - nidificazione - migrazione - costumi - caccia. Disegni di G. Minguzzi", "Practica iudiciaria Ja. de Bel. Visu. Solemnis & i…er Celsum Hugonem dissutum Cabilonensem Burgundum", "Discorso nel quale con le auttorità cosi de’ Genti…lamente, & impongono necessità ne gli atti humani", "Sacro arsenale overo prattica dell'Officio della S… Dedicato alla Santita di Nostro Sig. Clemente XI", "Della natura delle cose libri VI tradotti in verso…erina Alexiowna II imperatrice di tutte le Russie", "Italia. Viaggio pittoresco dall'Alpi all'Etna", "La Divina commedia illustrata da Gustavo Doré e di…ai migliori commenti per cura di Eugenio Camerini", "Lectura super quatuor libros Institutionum multorum doctorum et nuperrime domini Joannis de Gradibus", "Charles Baudelaire - Il veleno", "Italo Calvino - Si legge da soli anche quando si è in due", "Trattato della religione, e virtuti, che tener dev… per Scipione Metelli da Castelnuovo di Lunigiana", "Il nobile romano ossia trattato di nobiltà, libri …nte di Guardamiglio fratello uterino del medesimo", "Il buon governo degli affari domestici", "Dizionario biografico universale contenente le not…rrezioni e con una raccolta di tavole comparative", "Il club dei simpatici", "Dialogo dell'honore", "Il nipotismo di Roma. O vero relatione delle raggi…i. Del bene, e male che hanno portato alla chiesa", "Encomio della pazzia, composto in forma di declamazione per Erasmo, e tradotto in italiano", "Opere minori rivedute sulle migliori edizioni. Con note filologiche e critiche di F. L. Polidori", "Bestie del 900. Con tavole incise in nero e a colori di Mino Maccari", "[Opera omnia]: Thesaurus de uaria constructione. L…tae sylua. Statio totius anni. De poetica virtute", "Dialogi maritimi di M. Gioan Jacopo Bottazzo. Et a… diversi spiriti, dell’Accademia de gli Argonauti", "Flagellum daemonum. Exorcismos terribiles, potenti…onibus, & omnibus requisitis ad eorum expulsionem", "Storia naturale della regina delle api coll'arte d… Gelieu, anch'essi tradotti dalla lingua francese", "Memorie autobiografiche", "Le avventure di Pinocchio. Disegni a colori di Attilio Mussino", "Sermones tam quadrigesimales", "La historia di tutte le città, ville, fiumi, fonti…lla tradotta dalla lingua franzese nella italiana", "Del governo et amministratione di diversi regni, e…le, et buone così à tempi di pace, come di guerra", "Delle opere. Tomo primo contenente il Convito, e l…hia, le Rime, li Salmi penitenziali, ed il Credo]", "Teoria della prova nel processo penale. Traduzione… sull?originale tedesco dal Dr. Filippo Ambrosoli", "Bonaventura e C.", "Trattenimenti ... dove da vaghe donne, e da giovan…rate novelle; e cantate alcune amorose canzonette", "Speculum haereticae crudelitatis: in quo tam veter…signatae, proprijs suis coloris depictae exhibent", "La divina commedia, tratta da quella che pubblicar…nturi della compagnia di gesù. Divisa in tre tomi", "Il Principe e i Discorsi sopra la prima deca di Ti…Zambelli sul libro del Principe. Seconda edizione", "I colloqui. Liriche", "Adagiorum Chiliades iuxta locos communes digestae", "De festis iudaeorum et ethnicorum, hoc est, de ori…pud iudaeos, graecos, romanos, turcas et indianos", "Dissertatio satyrica physico-medico-moralis de pic… sive tabaci sternutatorii moderno abusu, et noxa", "Giovanni Pascoli - Nella nebbia", "Marguerite Yourcenar - Fondare biblioteche è come costruire ancora granai pubblici", "Rime di Francesco Petrarca, con l'interpretazione …iuntovi nuove ossservazioni per cura dell'Editore", "Filastrocche in cielo e in terra. Disegni di Bruno Munari", "Opera omnia, in unum proxime post illius mortem co…a plenius indicat. Accessit index locupletissimus", "Vite dei dodeci Visconti che signoreggiarono Milan…nichi. Et in quest'ultima impressione accresciute", "Principj di scienza nuova d’intorno alla comune na…i corretta, schiarita, e notabilmente accresciuta", "Il Mattino, il Mezzo giorno, il Vespro e la Notte.…eppe Parini preceduti dalla storia della sua vita", "Teorema", "Ragionamenti della lingua toscana, dove si parla d… oratore, & poeta volgari ... divisi in tre libri", "Prodromo gentilizio ovvero trattato delle armi ed …elle famiglie, preliminare alla Europa gentilizia", "Le rime", "Il brigantaggio o l'Italia dopo la dittatura di Garibaldi", "Lavorare stanca", "Oratio, Friburgi in funere D. Maximiliani Imp. Aug. habita", "Habiti antichi overo raccolta di figure delineate dal Gran Titiano, e da Cesare Vecellio", "Del fondamento del diritto di punire. Dissertazion…ettere di Mantova tenutasi nel dì 12. Giugno 1775", "Lettere edite ed inedite a vari suoi amici", "Fortunato Depero nelle opere e nella vita", "Il Petrarcha con l'espositione di m. Gio. Andrea G…con somma diligenza corretto, et ornato di figure", "L'Araldo veneto, overo universale armerista, metto…non solo à cavalieri, ma ad ogni stato di persone", "Bucolica Georgica et Aeneis ex cod. Mediceo-Lauren…rtationibus illustrata. Tomus primus ( - tertius)", "Nuove poesie di Enotrio Romano (Giosuè Carducci). Volume unico", "Ossi di seppia. Sesta edizione", "L'Institutioni imperiali del sacratissimo prencipe…cun titolo i quali contengon la materia del testo", "Karoli Magni et Ludovici Pii Christianiss. Regum e…um Capitula, sive leges ecclesiasticae et civiles", "Istoria delle immaginazioni stravaganti del signor…ioni, e che le impugnano. Traduzione dal francese", "Introduzione allo studio del diritto pubblico universale", "Come io vedo il mondo. Nuova edizione col Testamento spiriturale di A. Einstein", "De maleficiis tractatus, de inquirendis animaduert…usdem Angeli vita, per Thomam Diplobatacium edita", "Coelum austriacum augustissimorum romanorum caesar…natum. Discursus panegyrici, ac poemata historica", "Comoediae sex, ad optimorum exemplarium fidem rece…libris MSS. et eruditorum commentariis depromptae", "Giovanni Pascoli - Orfano", "Piero Angela - I figli di lettori tendono a essere lettori più degli altri"]
        self.__V = []
        year = date.today().year
        for i in range(n):
            if i > n//2:
                self.__V.append(Moderno(nomiMod[randint(0, len(nomiMod) - 1)], randint(year - 100, year), randint(1, 100)))
            else:
                self.__V.append(Antico(nomiAnt[randint(0, len(nomiAnt) - 1)], randint(1200, 1900), bool(getrandbits(1))))

    def libro_piu_costoso(self):
        max = self.V[0]
        for libro in self.V:
            if libro.valore() > max.valore():
                max = libro

        return max

    def visualizza(self):
        print("%100s%8s%14s" % ("Titolo", "Anno", "Costo"))
        even = True
        for libro in self.V:
            if even:
                print("\x1b[36m", end="")
            print("%100s%8d%13.2f€" % (libro.titolo, libro.anno_pubblicazione, libro.valore()))
            print("\x1b[0m", end="")
            even = not even
        print()

    @property
    def V(self):
        return self.__V

biblioteca = Biblioteca(100)
biblioteca.visualizza()
biblioteca.libro_piu_costoso().visualizza()
