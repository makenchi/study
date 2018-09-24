class Carro {
    private modelo: string
    private numDePortas: number
    private velocidade: number = 0

    constructor(modelo: string, numDePortas: number){
        this.modelo = modelo
        this.numDePortas = numDePortas
    }

    public acelerar(): void{
        this.velocidade = this.velocidade + 10
    }

    public parar(): void{
        this.velocidade = 0
    }

    public mostraVelocidade(): number{
        return this.velocidade
    }
}

class Concesionaria{
    private endereco: string
    private listaDeCarros: Array<Carro>

    constructor(endereco: string, listaCarros: Array<Carro>){
        this.endereco = endereco
        this.listaDeCarros = listaCarros
    }

    public fornecerEndereco(): string{
        return this.endereco
    }

    public mostrarListaDeCarros(): Array<Carro>{
        return this.listaDeCarros
    }
}

class Pessoa{
    private nome: string
    private carroPreferido: string
    private carro: any

    constructor(nomePessoa: string, carroP: string){
        this.nome = nomePessoa
        this.carroPreferido = carroP
    }

    public dizerNome(): string{
        return this.nome
    }

    public dizerCarroPreferido(): string{
        return this.carroPreferido
    }

    public comprarCarro(carroComprado: Carro): void{
        this.carro = carroComprado
    }

    public dizerCarroQueTem(): Carro{
        return this.carro
    }
}

/*criando os carro */
let carroA = new Carro('Batmovel',2)
let carroB = new Carro('Bugre aranha',4)
let carroC = new Carro('Uno',2)

/*monta lista de carros*/
let listaDeCarros: Carro[] = [carroA, carroB, carroC]
/*Também pode ser escrito assim
let listaDeCarros: Array<Carro> = [carroA, carroB, carroC]*/

let concessionaria = new Concesionaria('Metrópolis', listaDeCarros)
console.log(concessionaria.mostrarListaDeCarros())

/*Comprar o carro */
let cliente = new Pessoa('Bruce Wayne', 'Batmovel')

concessionaria.mostrarListaDeCarros().map((carro: Carro) => {
    if(carro['modelo'] == cliente.dizerCarroPreferido()){
        cliente.comprarCarro(carro)
    }
})

console.log(cliente.dizerCarroQueTem())