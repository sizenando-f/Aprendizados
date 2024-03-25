/* eslint-disable react/prop-types */
import Button from "../Button";
import Label from "../Label";
import Person from "../Person";
import styles from "./styles.module.css";

export default function Card(props) {
  return (
    <div className={styles.container}>
      <Person name={props.name} img={props.img} />
      <Label text={props.bio} />
      <Label text={props.phone} />
      <Label text={props.email} />
      <Button text="GitHub" link={props.githubUrl} />
      <Button text="LinkedIn" link={props.linkedinUrl} />
      <Button text="Twitter" link={props.twitterUrl} />
    </div>
  );
}
