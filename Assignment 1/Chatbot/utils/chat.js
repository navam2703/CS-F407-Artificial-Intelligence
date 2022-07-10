import { botMessages } from "./nlp"

export function updatedChat(chat, user_msg) {
    const user_message = {
        sender: "user",
        msg: user_msg
    }

    const bot_messages = botMessages(user_msg)

    return [...chat, user_message, ...bot_messages]
}