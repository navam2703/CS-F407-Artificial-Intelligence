export default function Tittle(props) {
    return (
        <div id="tittle" className="flex sm:items-center justify-between py-3 px-3 shadow-md rounded-md rounded-b-none bg-slate-300">
            <div className="relative flex items-center space-x-4">
                <div className="flex flex-col leading-tight">
                    <div className="text-2xl mt-1 flex items-center">
                        <span className="text-black mr-3">AI Chat Bot</span>
                    </div>
                    <span className="text-lg text-gray-600">Eateries Helper</span>
                </div>
            </div>
        </div>
    );
}
