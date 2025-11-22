import { useState } from "react";
import "./App.css";

const Botao = () => {
  const [contador, setContador] = useState(0);

  function minhaFuncao() {
    setContador(contador + 1);
  }

  return <button onClick={minhaFuncao}>Cliques: {contador}</button>;
};

const CampoTexto = () => {
  const [texto, setTexto] = useState("");

  return (
    <div>
      <input type="text" onChange={(e) => setTexto(e.target.value)} />
      <p>{texto}</p>
    </div>
  );
};

const tarefas = ["Estudar React", "Fazer café", "Dominar o mundo"];

const Lista = () => {
  return (
    <ul>
      {tarefas.map((item) => (
        <li key={item}>{item}</li>
      ))}
    </ul>
  );
};

function App() {
  return (
    <>
      <Botao></Botao>
      <CampoTexto></CampoTexto>
      <Lista></Lista>
    </>
  );
}

export default App;
