/* eslint-disable react/prop-types */
import styles from "./styles.module.css";

export default function Button(props) {
  return (
    <div className={styles.container}>
      <a href={props.link}>
        <button className={styles.btn}>{props.text}</button>
      </a>
    </div>
  );
}
