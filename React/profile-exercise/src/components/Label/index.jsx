/* eslint-disable react/prop-types */
import styles from "./styles.module.css";
export default function Label(props) {
  return (
    <div className={styles.label}>
      <p>{props.text}</p>
    </div>
  );
}
