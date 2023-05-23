'use client'

import { useEffect, useState } from "react"
import { motion } from "framer-motion"

export default function Home() {
    const [LPG, setLPG] = useState()
    const [CO, setCO] = useState()
    const [Smoke, setSmoke] = useState()

    useEffect(() => {
        const getSensorData = async () => {
            try {
                const response = await fetch("http://localhost:3000/data");
                const data = await response.json();
                setLPG(data.lpg)
                setCO(data.co)
                setSmoke(data.smoke)
            } catch (error) {
                console.error('Error fetching data:', error);
            }
        }

        getSensorData()

        const intervalID = setInterval(getSensorData, 1000)

        return () => clearInterval(intervalID)
    },[])

    return (
        <motion.div
            animate={{
                scale: [0.98, 1],
            }}
            transition={{
                duration: 1,
                repeat: Infinity,
                repeatType: 'reverse'
            }}
        >
            <main className="flex items-center justify-center h-screen">
                <div className="max-w-sm rounded-lg overflow-hidden shadow-lg bg-white">
                    <img className="w-full rounded-b-lg" src="/weather_display.jpg" alt="Sunset in the mountains" />
                    <div className="px-6 py-4">
                        <div className="font-bold text-xl mb-2">Current Air Quality</div>
                        <div className="text-slate-700 my-5 font-medium">
                            {
                                <div className="flex flex-row justify-start items-center">
                                    <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor" className="w-6 h-6">
                                    <path strokeLinecap="round" strokeLinejoin="round" d="M9.75 3.104v5.714a2.25 2.25 0 01-.659 1.591L5 14.5M9.75 3.104c-.251.023-.501.05-.75.082m.75-.082a24.301 24.301 0 014.5 0m0 0v5.714c0 .597.237 1.17.659 1.591L19.8 15.3M14.25 3.104c.251.023.501.05.75.082M19.8 15.3l-1.57.393A9.065 9.065 0 0112 15a9.065 9.065 0 00-6.23-.693L5 14.5m14.8.8l1.402 1.402c1.232 1.232.65 3.318-1.067 3.611A48.309 48.309 0 0112 21c-2.773 0-5.491-.235-8.135-.687-1.718-.293-2.3-2.379-1.067-3.61L5 14.5" />
                                    </svg>
                                    <div className="ms-5">{LPG} ppm</div>
                                </div>
                            }
                            {
                                <div className="flex flex-row justify-start items-center">
                                    <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor" className="w-6 h-6">
                                        <path strokeLinecap="round" strokeLinejoin="round" d="M2.25 15a4.5 4.5 0 004.5 4.5H18a3.75 3.75 0 001.332-7.257 3 3 0 00-3.758-3.848 5.25 5.25 0 00-10.233 2.33A4.502 4.502 0 002.25 15z" />
                                    </svg>
                                    <div className="ms-5">{CO} ppm</div>
                                </div>
                            }
                            {
                                <div className="flex flex-row justify-start items-center">
                                    <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor" className="w-6 h-6">
                                        <path strokeLinecap="round" strokeLinejoin="round" d="M15.362 5.214A8.252 8.252 0 0112 21 8.25 8.25 0 016.038 7.048 8.287 8.287 0 009 9.6a8.983 8.983 0 013.361-6.867 8.21 8.21 0 003 2.48z" />
                                        <path strokeLinecap="round" strokeLinejoin="round" d="M12 18a3.75 3.75 0 00.495-7.467 5.99 5.99 0 00-1.925 3.546 5.974 5.974 0 01-2.133-1A3.75 3.75 0 0012 18z" />
                                    </svg>
                                    <div className="ms-5">{Smoke} ppm</div>
                                </div>
                            }
                        </div>
                        <p className="text-gray-700 font-extralight">
                            This is our final project for Embedded Systems class where this simple system can sense the current air condition on your living environment
                        </p>
                    </div>
                    <div className="px-6 pt-4 pb-2">
                        <span className="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2">#arduino</span>
                        <span className="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2">#mq2</span>
                        <span className="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2">#serial</span>
                    </div>
                </div>
            </main>
        </motion.div>
    )
}