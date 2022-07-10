export function botMessages(user_msg) {
    let messages = []
    let bot_msg="Sorry, I didn't understand that."
    let flag = false

    if(user_msg.match(/.*i'm.*/gi) || user_msg.match(/.*i am.*/gi)) {
        if(user_msg.match(/.*hungry.*/gi)) {
            bot_msg="If you are hungry, Tell me what you like to eat? Maggi/Burger/Sandwich/Ice cream"
            messages.push(getMessageObj(bot_msg))
            flag = true
        } else {
            bot_msg="Hi, I am a bot! How can I help you?";
            messages.push(getMessageObj(bot_msg))
        }
    }

    if(user_msg.match(/.*hi.*/gi)) {
	    bot_msg="Hi, I am a bot! How can I help you?";
        messages.push(getMessageObj(bot_msg))
    }

    if(user_msg.match(/.*hungry.*/gi) && !flag) {
        bot_msg="If you are hungry, Tell me what you like to eat? Maggi/Burger/Sandwich/Ice cream"
        messages.push(getMessageObj(bot_msg))
    }

    if(user_msg.match(/.*maggi.*/gi)) {
	    bot_msg="You may like yumppies or hotspot.";
        messages.push(getMessageObj(bot_msg))
    }
    
    if(user_msg.match(/.*burger.*/gi)) {
	    bot_msg="You may like SFC.";
        messages.push(getMessageObj(bot_msg))
    }
    
    if(user_msg.match(/.*sandwich.*/gi)) {
        bot_msg="You may like wich please.";
        messages.push(getMessageObj(bot_msg))
    }

    if(user_msg.match(/.*ice cream.*/gi)) {
	    bot_msg="You may like Amul.";
        messages.push(getMessageObj(bot_msg))
    }
    
    if(user_msg.match(/.*weather.*/gi)) {
        bot_msg="The current temperature at Hyderabad is 35 degrees.";
        messages.push(getMessageObj(bot_msg))
    }

    if(user_msg.match(/.*thank you.*/gi) || user_msg.match(/.*bye.*/gi)) {
        bot_msg="Thank you, Bye!!";
        messages.push(getMessageObj(bot_msg))
    }

    if(messages.length==0) {
        messages.push(getMessageObj(bot_msg))

        bot_msg="If you are hungry, Tell me what you like to eat? Maggi/Burger/Sandwich/Ice cream"
        messages.push(getMessageObj(bot_msg))

        bot_msg="If you want to know weather, Type weather"
        messages.push(getMessageObj(bot_msg))
    }

    return messages
}

function getMessageObj(bot_msg) {
    return {
        sender: "bot",
        msg: bot_msg
    };
}
