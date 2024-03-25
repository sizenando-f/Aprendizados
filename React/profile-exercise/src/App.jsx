import Profile from "./components/Profile";
import img from "./assets/me.jpeg";

export default function App() {
  return (
    <>
      <Profile
        name="Sizenando França"
        img={img}
        bio="Software Engineer and FullStack Web Developer"
        email="myemail@gmail.com"
        phone="+556740028922"
        githubUrl="https://github.com/sizenando-f"
        linkedinUrl="https://www.linkedin.com/in/sizenando-fran%C3%A7a-b077b9207/"
        twitterUrl="https://x.com/FrancaSizenando"
      />
    </>
  );
}
