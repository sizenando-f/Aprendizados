/* eslint-disable react/prop-types */
import styles from "./styles.module.css";

export default function Person(props) {
  function handleClick(ev) {
    console.log(ev);
    alert("Você está seguindo!");
  }

  return (
    <div className={styles.container}>
      <img src={props.img} alt="Foto" className={styles.img} />
      <h1>{props.name}</h1>
      <button onClick={handleClick} className={styles.followBtn}>
        Follow
      </button>
    </div>
  );
}
