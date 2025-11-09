import { Tooltip, TooltipArrow, TooltipContent, TooltipProvider, TooltipTrigger } from '@/components/ui/tooltip'

interface Props {
  description: string
}

export default function DescriptionWithTooltip({ description }: Props) {
  return (
    <TooltipProvider delayDuration={200}>
      <Tooltip>
        <TooltipTrigger asChild>
          <p className="flex-1 min-w-0 overflow-hidden text-ellipsis whitespace-nowrap text-white text-sm font-semibold [text-shadow:0_1px_3px_rgba(0,0,0,0.75)]">
            {description}
          </p>
        </TooltipTrigger>
        <TooltipContent side="top" sideOffset={8}>
          {description}
          <TooltipArrow width={10} height={8} />
        </TooltipContent>
      </Tooltip>
    </TooltipProvider>
  )
}

