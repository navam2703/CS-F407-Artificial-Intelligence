import React, { useContext, useState } from 'react';

export const ChatContext = React.createContext()
export const ChatUpdateContext = React.createContext()

export function useChat() {
    return useContext(ChatContext)
}

export function useChatUpdate() {
    return useContext(ChatUpdateContext)
}

export function ChatProvider({ children }) {
    const [chat, setChat] = useState([]);
    
    return (
        <ChatContext.Provider value= { chat }>
            <ChatUpdateContext.Provider value= { setChat }>
                { children }
            </ChatUpdateContext.Provider>
        </ChatContext.Provider>
    )
}
