/* eslint-disable react/prop-types */
import styles from "./styles.module.css";

export default function Person(props) {
  return (
    <div className={styles.container}>
      <img src={props.img} alt="Foto" className={styles.img} />
      <h1>{props.name}</h1>
    </div>
  );
}
