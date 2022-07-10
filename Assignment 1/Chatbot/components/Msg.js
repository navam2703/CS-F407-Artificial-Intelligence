import Botmsg from "./Botmsg";
import Usermsg from "./Usermsg";

export default function Msg({ sender, msg , i}) {
    console.log(i+ "| " +sender+" : "+msg)
    return(
        <>
            { (sender=="user")? <Usermsg msg={msg} /> : <Botmsg msg={msg} /> }
        </>
    )
}