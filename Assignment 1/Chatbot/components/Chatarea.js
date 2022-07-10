import { useChat } from "./ChatContext";
import Msg from "./Msg";

export default function Chatarea() {
    const chat = useChat();
    const i = 0
    return(
        <div id="chatarea" className="flex flex-col space-y-4 p-3 overflow-y-auto scrollbar-thumb-blue scrollbar-thumb-rounded scrollbar-track-blue-lighter scrollbar-w-2 scrolling-touch">
                { chat.map((m) => <Msg sender={m["sender"]} msg= {m["msg"]} i={i++}/> ) }        
        </div>
    );
}
