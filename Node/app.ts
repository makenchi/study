/*Importando os módulos*/
import{Carro} from './Carro'
import{Concesionaria} from './Concessionaria'
import{Pessoa} from './Pessoa'

/*criando os carro*/
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
console.log(concessionaria.fornecerHoraDeFunc())