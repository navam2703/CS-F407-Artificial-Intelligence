import React from 'react';
import { updatedChat } from '../utils/chat';
import { useChat, useChatUpdate } from './ChatContext';

export default function Inputform() {
    const chat = useChat();
    const setChat = useChatUpdate();
    let msgRef = React.createRef();

    return (
        <div id="input" className="border-t-2 border-gray-200 shadow-md px-2 py-2 mb-2 sm:mb-0 relative flex rounded-md bg-slate-300">
            <input id="message" ref={msgRef} type="text" placeholder="Write your message!" className="border border-black w-4/5 py-3 px-3 focus:outline-none focus:placeholder-gray-400 text-gray-600 placeholder-gray-600 bg-gray-200 rounded-md shadow-sm focus:shadow-md"/>
            <div className="absolute right-0 items-center inset-y-0 hidden sm:flex pr-2 py-2">
                <button type="button" className="inline-flex items-center justify-center rounded-lg px-8 py-3 transition duration-500 ease-in-out border border-black shadow-sm hover:shadow-lg bg-blue-200 hover:bg-blue-500"
                    onClick={ () => { 
                        setChat(updatedChat(chat, msgRef.current.value));
                        msgRef.current.value="";
                    }}>
                    <span className="font-bold text-black">Send</span>
                </button>
            </div>
        </div>
    );
}