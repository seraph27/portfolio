import type { APIRoute } from 'astro'

export const prerender = false

export const POST: APIRoute = async ({ params, request }) => {
  const beatmapsetId = params.id
  if (!beatmapsetId) {
    return new Response(JSON.stringify({ error: 'Beatmapset ID is required' }), {
      status: 400,
      headers: { 'Content-Type': 'application/json' },
    })
  }

  try {
    const body = await request.json()
    const action = body.action // 'favourite' or 'unfavourite'

    // Get current favorites from localStorage (client-side) or create a simple in-memory store
    // For a real implementation, you'd use a database
    // For now, we'll use a simple approach with localStorage on the client side
    
    // Since this is server-side, we'll return success and let the client handle storage
    // In a real app, you'd save to a database here
    
    return new Response(
      JSON.stringify({
        success: true,
        action,
        beatmapsetId,
      }),
      {
        status: 200,
        headers: { 'Content-Type': 'application/json' },
      },
    )
  } catch (error) {
    console.error('Error updating favourite:', error)
    return new Response(JSON.stringify({ error: 'Internal server error' }), {
      status: 500,
      headers: { 'Content-Type': 'application/json' },
    })
  }
}

export const GET: APIRoute = async ({ params }) => {
  const beatmapsetId = params.id
  if (!beatmapsetId) {
    return new Response(JSON.stringify({ error: 'Beatmapset ID is required' }), {
      status: 400,
      headers: { 'Content-Type': 'application/json' },
    })
  }

  // Return default state - in a real app, you'd check the database
  return new Response(
    JSON.stringify({
      has_favourited: false,
      favourite_count: 0,
    }),
    {
      status: 200,
      headers: { 'Content-Type': 'application/json' },
    },
  )
}

